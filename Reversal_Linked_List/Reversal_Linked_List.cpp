// All C headers have a C++ version, which should used instead - cstdlib is C++'s stdlib.h.
#include <cstdlib> // contains EXIT_SUCCESS
#include <memory> // contains std::unique_ptr
#include <iostream> // contains std::cout, the console output stream, and its generalization std::ostream.
#include <iterator> // contains std::rbegin/rend for reverse iteration.
#include <initializer_list> // contains std::initializer_list

//Using a template allows us to only write the linked list once and then create different kinds of linked lists. That way we can distinguish between lists of integers and lists of strings and will never accidentally pass one when the other is required.
template<typename T> // T is our placeholder name for the type of element in the linked list.

class linked_list // "snake case" is what the standard library uses, so in the interest of consistency we will too.
{
	// Friend function for printing a linked_list. (Note that this is a free function (i.e. not attached to any class), not a member function, despite being declared here, due to the friend keyword.)
	// It is allowed to access the list's private parts. Friends should be used sparingly - they often indicate that your public interface is lacking some functionality, which is true in this case (we lack a way of retrieving the elements in the list), but in the interest of brevity/simplicity we're doing it this way.
	// Note that we pass the list as a const reference - this means we cannot modify it (a print function shouldn't do that, after all) and it won't be passed as a copy (the default).
	friend std::ostream& operator<<( std::ostream& os, const linked_list& list ) {
		bool first = true;
		os << '[';
		for( auto curNode = list._first.get(); curNode; curNode = curNode->next.get() ) {
			if( first ) {
				first = false;
			} else {
				os << ", ";
			}
			os << curNode->element;
		}
		os << ']';
		return os;
	}

	struct node;
	// Helper type alias so we don't need to write so much. Since the node definition is not until later, we need the above forward declaration for this to work.
	using node_ptr = std::unique_ptr<node>;

	//The public part of the class is what users can access. One of the main ideas of object oriented programming is encapsulation: We can hide the implementation details from our users so they can't accidentally (or intentionally) mess with the internal consistency of the data structure.
public:
	// An initializer_list allows us to define the contents of the list when creating one.
	linked_list( std::initializer_list<T> elements ) {
		// iterate through the elements in the list in reverse order and add them to the front
		for( auto it = std::rbegin( elements ); it != std::rend( elements ); ++it ) {
			push_front( *it );
		}
	}

	// Since we defined a custom constructor (with an initializer_list), the default constructor with no arguments won't be automatically generated. We'd like to have it though. While we're at it we can declare that it will never throw, since it only calls std::unique_ptr's default constructor, which is also noexcept.
	linked_list() noexcept = default;

	// push_front adds a new element to the front of our linked list.
	template<typename U>
	// && is a universal reference. Basically this means if this function is called with a temporary object, we don't need to copy it into the list, we can move it there, which may be a lot cheaper. This is called perfect forwarding. Some types are move-only, i.e. can't be copied; perfect forwarding allows us to still use them here.
	// Note that we don't declare this function noexcept because std::make_unique can throw exceptions for numerous reasons.
	void push_front( U&& element ) {
		// Note the order here, it is intentional: We first create the new node containing the element. We do not yet set its next pointer. If something goes awry during construction, an exception may be thrown.
		node_ptr newNode = std::make_unique<node>( std::forward<U>( element ) );
		// Only then do we move the former first node into the node's next field. _first is now a null-pointer. Had we passed std::move(_first) as an argument to node's constructor and then encountered an exception there, _first would be a null-pointer and our list thus empty.
		// But this way, if something goes wrong, the (observable) state of our list is unchanged. This is called the strong exception guarantee and helps us stay consistent in the face of errors.
		// You might wonder what would happen if the following assignment were to throw an exception - wouldn't we still lose our list's contents? We would, but std::unique_ptr::operator= (i.e. assigning to a unique_ptr) is "noexcept", i.e. gauranteed to never throw an exception.
		newNode->next = std::move( _first );
		_first = std::move( newNode );
	}

	// Since the only operation we execute is assigning to an std::unique_ptr, which is noexcept, this function is noexcept as well. This is useful information both to our users and the compiler, which can do more aggressive optimization knowing this.
	void reverse_iteratively() noexcept {
		node_ptr prev;
		// Note how since std::unique_ptr is non-copyable we have to move the value around here. This may seem complicated, but it ensures we never leak memory or do a double free.
		node_ptr current = std::move( _first );
		while( current ) {
			auto next = std::move( current->next );
			current->next = std::move( prev );
			prev = std::move( current );
			current = std::move( next );
		}
		_first = std::move( prev );
	}

	void reverse_recursively() noexcept {
		// nullptr is the modern, safe way of expressing a null pointer. It will be implicitly converted to an std::unique_ptr using the unique_ptr(nullptr_t) constructor. (nullptr_t is the type of nullptr.) This is shorter and arguably more readable than writing node_ptr() or node_ptr{} but functionally identical.
		_first = std::move( reverse_recursively( nullptr, std::move( _first ) ) );
	}

private:
	// C++ allows us to have multiple functions with the same name as long as their parameters differ - this is called overloading.
	static node_ptr reverse_recursively( node_ptr prev, node_ptr current ) noexcept {
		if( !current ) {
			return std::move( prev );
		}
		auto next = std::move( current->next );
		current->next = std::move( prev );
		return reverse_recursively( std::move( current ), std::move( next ) );
	}

	// How exactly a node in our linked list looks is of no concern to the user, so we put it in the private part. That way we can change it without breaking anybody's code.
	// A node consists of an element and a pointer to the next node.
	struct node {
		// This noexcept declaration means the following: This function is noexcept if calling T's constructor with the forwarded value  is noexcept.
		template<typename U>
		node( U&& elem ) noexcept( noexcept( T( std::forward<U>( elem ) ) ) )
			// This is a so-called initialisation list. It allows us to define the initial state of the member variables in the class.
			: element( std::forward<U>( elem ) ) // Again: Perfect forwarding potentially makes our code more efficient.
		{
			// If we assigned element here instead, it would first be default-constructed during initialisation. That would be unnecessary overhead and would also limit us to types that can be default-constructed in the first place (i.e. have a 0 argument constructor) - not all can.
		}
		T element;
		// A unique pointer "owns" the memory it points to. That means once the pointer "dies", the memory is freed. This way we don't need to do any manual book keeping. This is possible without any garbage collection overhead thanks to the RAII principle, one of the most important concepts in C++.
		node_ptr next;
	};

	// A side-effect of using the move-only unique_ptr type here is that our list cannot be copied by default. If we want it to be copyable, we have to define our own copy constructor (and copy assignment).
	node_ptr _first;
};

/*
Entrypoint into our program - execution starts here.
*/
int main() {
	// Initialize the list using an initializer_list
	linked_list<int> l{ 1, 2, 3 };
	std::cout << "original list: " << l << std::endl;
	l.reverse_iteratively();
	std::cout << "reversed list: " << l << std::endl;
	// Since we have a generic linked_list implementation we can also create other types of lists - say a list of lists of integers. We use the default constructor here to create an empty list.
	linked_list<linked_list<int>> l2;
	std::cout << "Empty list: " << l2 << std::endl;
	l2.push_front( std::move( l ) );
	l2.push_front( linked_list<int>{ 4, 5, 6 } );
	std::cout << "Nested list: " << l2 << std::endl;
	l2.reverse_recursively();
	std::cout << "Reversed nested list: " << l2 << std::endl;
	// note that we have no way of accessing the elements of the list yet, so we can't reverse a list inside the list.
	return EXIT_SUCCESS; // Using named constants is preferrable to "magic numbers". Not everybody knows that 0 means "success" in this context.
}
