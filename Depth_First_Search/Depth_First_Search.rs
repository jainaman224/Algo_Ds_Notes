// use std::rc::{Rc, Weak};
// use std::cell::RefCell;

struct Vertex<V> {
	value: V,
	neighbours: Vec<Weak<RefCell<Vertex<V>>>>,
}


fn dft_helper(start: Rc<RefCell<Vertex<V>>>, f: &impl Fn(&V), s: &mut Vec<*const Vertex<V>>) {
	s.push(start.as_ptr());
	(f)(&start.borrow().value);
	for n in &start.borrow().neighbours {
		let n = n.upgrade().expect("Invalid neighbor");
		if s.iter().all(|&p| p != n.as_ptr()) {
			Self::dft_helper(n, f, s);
		}
	}
}