class BinarySearchTree {
	private var head: node? = null

	class node(var data: Int) {
		var left: node? = null
		var right: node? = null

	}

	fun Insert(value: Int) {
		val temp = node(value)
		if (head == null)
			head = temp
		else {
			var current: node?
			current = head
			while (current != null) {
				if (value < current.data) {
					if (current.left != null)
						current = current.left
					else {
						current.left = temp
						return
					}
				} else {
					if (current.right != null)
						current = current.right
					else {
						current.right = temp
						return
					}
				}
			}
		}
	}
	
	fun Search(value: Int) {
		var current: node?
		current = head
		while (current != null) {
			current = if (value < current.data) current.left else if (value > current.data) current.right else {
				println("Element $value Found")
				return
			}
		}
		println("Element $value not Found")
	}

	fun Min_Value(head: node?): Int {
		var temp = head
		while (temp!!.left != null)
			temp = temp.left
		return temp.data
	}

	fun Delete_Key(head: node?, value: Int): node? {
		if (head == null)
			return head
		if (value < head.data)
			head.left = Delete_Key(head.left, value)
		else if (value > head.data)
			head.right = Delete_Key(head.right, value)
		else {
			if (head.left == null)
				return head.right
			else if (head.right == null)
				return head.left
			head.data = Min_Value(head.right)
			head.right = Delete_Key(head.right, head.data)
		}
		return head
	}

	fun Delete(value: Int) {
		head = Delete_Key(head, value)
	}
	
}

fun main() {
	val BST = BinarySearchTree()
	BST.Insert(5)
	BST.Insert(7)
	BST.Insert(9)
	BST.Insert(8)
	BST.Insert(6)
	BST.Insert(4)
	BST.Search(9)
	BST.Search(2)
	BST.Delete(7)
	BST.Delete(5)
	BST.Delete(4)
	BST.Search(9)
	BST.Search(2)
	BST.Search(5)
	BST.Search(6)
}

/* Output
Element 9 Found
Element 2 not Found
Element 9 Found
Element 2 not Found
Element 5 not Found
Element 6 Found
*/
