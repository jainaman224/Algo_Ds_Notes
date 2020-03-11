use std::cmp::Ordering;
use std::collections::BinaryHeap;
use std::usize;
 
 
struct Grid<T> {
    nodes: Vec<Node<T>>,
}
 
struct Node<T> {
    data: T,
    edges: Vec<(usize,usize)>,
}
 
#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    node: usize,
    cost: usize,
}
 
// Manually implement Ord so we get a min-heap instead of a max-heap
impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        other.cost.cmp(&self.cost)
    }
}
 
impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}
 
type WeightedEdge = (usize, usize, usize);
 
impl<T> Grid<T> {
    fn new() -> Self {
        Grid { nodes: Vec::new() }
    }
 
    fn add_node(&mut self, data: T) -> usize {
        let node = Node {
            edges: Vec::new(),
            data: data,
        };
        self.nodes.push(node);
        self.nodes.len() - 1
    }
 
    fn create_edges<'a, I>(&mut self, iterator: I) where I: IntoIterator<Item=&'a WeightedEdge> {
        for &(start,end,weight) in iterator.into_iter() {
            self.nodes[start].edges.push((end,weight));
            self.nodes[end].edges.push((start,weight));
        }
 
    }
 
    fn find_path(&self, start: usize, end: usize) -> Option<(Vec<usize>, usize)> {
        let mut dist = vec![(usize::MAX, None); self.nodes.len()];
 
        let mut heap = BinaryHeap::new();
        dist[start] = (0, None);
        heap.push(State {
            node: start,
            cost: 0,
        });
 
        while let Some(State { node, cost }) = heap.pop() {
            if node == end {
                let mut path = Vec::with_capacity(dist.len() / 2);
                let mut current_dist = dist[end];
                path.push(end);
                while let Some(prev) = current_dist.1 {
                    path.push(prev);
                    current_dist = dist[prev];
                }
                path.reverse();
                return Some((path, cost));
            }
 
            if cost > dist[node].0 {
                continue;
            }
            for edge in &self.nodes[node].edges {
                let next = State {
                    node: edge.0,
                    cost: cost + edge.1,
                };
                if next.cost < dist[next.node].0 {
                    dist[next.node] = (next.cost, Some(node));
                    heap.push(next);
                }
            }
        }
        None
    }
}
 
fn main() {
    let mut grid = Grid::new();
    let (a,b,c,d,e,f) = (grid.add_node("a"), grid.add_node("b"),
                         grid.add_node("c"), grid.add_node("d"),
                         grid.add_node("e"), grid.add_node("f"));
 
    grid.create_edges(&[
        (a,b,7) ,(a,c,9) ,(a,f,14),
        (b,c,10),(b,d,15),(c,d,11),
        (c,f,2) ,(d,e,6) ,(e,f,9) ,
    ]);
 
    let (path, cost) = grid.find_path(a,e).unwrap();
 
    print!("{}", grid.nodes[path[0]].data);
    for i in path.iter().skip(1) {
        print!(" -> {}", grid.nodes[*i].data);
    }
    println!("\nCost: {}", cost);
 
}
