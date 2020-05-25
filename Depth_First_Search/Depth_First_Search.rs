use std::rc::{Rc, Weak};
use std::cell::RefCell;

struct Vertex<V> {
    value: V,
    neighbours: Vec<Weak<RefCell<Vertex<V>>>>,
}

type RcVertex<V> = Rc<RefCell<Vertex<V>>>;

struct Graph<V> {
    vertices: Vec<RcVertex<V>>,
}

impl<V> Graph<V> {
    fn new() -> Self {
        Graph { vertices: vec![] }
    }
    
    fn new_vertex(&mut self, value: V) -> RcVertex<V> {
        self.add_vertex(Vertex { value, neighbours: Vec::new() })
    }
    
    fn add_vertex(&mut self, v: Vertex<V>) -> RcVertex<V> {
        let v = Rc::new(RefCell::new(v));
        self.vertices.push(Rc::clone(&v));
        v
    }
    
    fn add_edge(&mut self, v1: &RcVertex<V>, v2: &RcVertex<V>) {
        v1.borrow_mut().neighbours.push(Rc::downgrade(&v2));
        v2.borrow_mut().neighbours.push(Rc::downgrade(&v1));
    }
    
    fn dft(start: RcVertex<V>, f: impl Fn(&V)) {
        let mut s = vec![];
        Self::dft_helper(start, &f, &mut s);
    }
    
    fn dft_helper(start: RcVertex<V>, f: &impl Fn(&V), s: &mut Vec<*const Vertex<V>>) {
        s.push(start.as_ptr());
        (f)(&start.borrow().value);
        for n in &start.borrow().neighbours {
            let n = n.upgrade().expect("Invalid neighbor");
            if s.iter().all(|&p| p != n.as_ptr()) {
                Self::dft_helper(n, f, s);
            }
        }
    }
}

// Sample Input and Output

fn main() {
    let mut g = Graph::new();
    
    let v1 = g.new_vertex(1);
    let v2 = g.new_vertex(2);
    let v3 = g.new_vertex(3);
    let v4 = g.new_vertex(4);
    let v5 = g.new_vertex(5);
    
    g.add_edge(&v1, &v2);
    g.add_edge(&v1, &v4);
    g.add_edge(&v1, &v5);
    g.add_edge(&v2, &v3);
    g.add_edge(&v3, &v4);
    g.add_edge(&v4, &v5);
    
    Graph::dft(v1, |v| println!("{}", v));
}
