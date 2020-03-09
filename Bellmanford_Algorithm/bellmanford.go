package main

import (
	"container/list"
	"fmt"
	"regexp"
	"strconv"
	"strings"
)

func main() {

	/*
	   A|B,7|C,9|F,20
	   Connect A with B with an edge from A "to" B of weight value 7
	   Connect A with C with an edge from A "to" C of weight value 9
	   Connect A with F with an edge from A "to" F of weight value 20

	   F|A,20|C,2|E,9
	   Connect F with A with an edge from F "to" A of weight value 20
	   Connect F with C with an edge from F "to" C of weight value 2
	   Connect F with E with an edge from F "to" E of weight value 9
	*/

	str1 := `
S|A,7|B,6
A|C,-3|T,9
B|A,8|T,-4|C,5
C|B,-2
T|S,2|C,7
`
	G1 := ConstructDirectedGraph(str1)
	result_list1 := G1.BellmanFordShortestPath(G1.GetVertexByID("S"), G1.GetVertexByID("T"))

	fmt.Print("Graph 01 Bellman-Ford: ")
	for vtx := result_list1.Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v(=%v) → ", vtx.Value.(*Vertex).ID, vtx.Value.(*Vertex).timestamp_d)
	}

	println()

	for vtx := G1.GetVertexList().Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v(=%v) \n", vtx.Value.(*Vertex).ID, vtx.Value.(*Vertex).timestamp_d)
	}
	println()

	/*
	   Target: T , Predecessor Back(): B , Source: S
	   Target: B , Predecessor Back(): C , Source: S
	   Target: C , Predecessor Back(): T , Source: S
	   Target: A , Predecessor Back(): B , Source: S
	   Target: S , Predecessor Back(): T , Source: S
	   Graph 01 Bellman-Ford: S(=0) → A(=7) → C(=4) → B(=2) → T(=-2) →
	   S(=0)
	   A(=7)
	   B(=2)
	   C(=4)
	   T(=-2)
	*/

	str2 := `
S|A,15|B,14|C,9
A|S,15|B,5|D,20|T,44
B|S,14|A,5|D,30|E,18
C|S,9|E,24
D|A,20|B,30|E,2|F,11|T,16
E|B,18|C,24|D,2|F,6|T,19
F|D,11|E,6|T,6
T|A,44|D,16|F,6|E,19
`

	G2 := ConstructDirectedGraph(str2)
	result_list2 := G2.BellmanFordShortestPath(G2.GetVertexByID("S"), G2.GetVertexByID("T"))

	fmt.Print("Graph 02 Bellman-Ford: ")
	for vtx := result_list2.Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v(=%v) → ", vtx.Value.(*Vertex).ID, vtx.Value.(*Vertex).timestamp_d)
	}

	println()

	for vtx := G2.GetVertexList().Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v(=%v) \n", vtx.Value.(*Vertex).ID, vtx.Value.(*Vertex).timestamp_d)
	}
	println()

	fmt.Print("Using list, Predecessor of T: ")
	for vtx := G2.GetVertexByID("T").Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v ", vtx.Value.(*Vertex).ID)
	}
	println()

	fmt.Print("Using list, Predecessor of F: ")
	for vtx := G2.GetVertexByID("F").Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v ", vtx.Value.(*Vertex).ID)
	}
	println()

	fmt.Print("Using list, Predecessor of E: ")
	for vtx := G2.GetVertexByID("E").Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v ", vtx.Value.(*Vertex).ID)
	}
	println()

	fmt.Print("Using list, Predecessor of B: ")
	for vtx := G2.GetVertexByID("B").Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v ", vtx.Value.(*Vertex).ID)
	}
	println()

	fmt.Print("Using list, Predecessor of S: ")
	for vtx := G2.GetVertexByID("S").Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
		fmt.Printf("%v ", vtx.Value.(*Vertex).ID)
	}
	println()

	/*
	   Target: T , Predecessor Back(): F , Source: S
	   Target: F , Predecessor Back(): T , Source: S
	   Target: E , Predecessor Back(): T , Source: S
	   Target: D , Predecessor Back(): T , Source: S
	   Target: B , Predecessor Back(): E , Source: S
	   Target: A , Predecessor Back(): T , Source: S
	   Target: S , Predecessor Back(): C , Source: S

	   Right Path is ...
	   Graph 02 Shortest Path & Weight: S(=0) → B(=14) → E(=32) → F(=38) → T(=44) →


	   Graph 02 Bellman-Ford: S(=0) → A(=15) → B(=14) → D(=34) → E(=32) → F(=38) → T(=44) →
	   S(=0)
	   A(=15)
	   B(=14)
	   C(=9)
	   D(=34)
	   T(=44)
	   E(=32)
	   F(=38)

	   Using list, Predecessor of T: A D E F
	   Using list, Predecessor of F: D E T
	   Using list, Predecessor of E: B C D F T
	   Using list, Predecessor of B: S A D E
	   Using list, Predecessor of S: A B C

	   Therefore, if there is negative-weight-value edges, we use Bellman-Ford
	   and if there is no negatives, we can use Dijkstra
	   and then we can keep the same backtracking function.
	*/
}

/////////// Bellman-Ford ///////////
/*
	BellmanFordShortestPath(G, source, target)
		// Initialize-Single-Source(G,s)
		for each vertex v ∈ G.V
			v.d = ∞
			v.π = nil
		source.d = 0

		// for each vertex
		for  i = 1  to  |G.V| - 1
			for  each edge (u, v) ∈ G.E
				Relax(u, v, w)

		for  each edge (u, v) ∈ G.E
			if  v.d > u.d + w(u, v)
				if v.d > u.d + w(u,v)
					return FALSE

		return TRUE
*/
func (G *Graph) BellmanFordShortestPath(source, target *Vertex) *list.List {

	for vtx := G.GetVertexList().Front(); vtx != nil; vtx = vtx.Next() {
		vtx.Value.(*Vertex).timestamp_d = 9999999999
		vtx.Value.(*Vertex).Predecessor.Init()
	}
	source.timestamp_d = 0

	for v := G.GetVertexList().Front(); v != nil; v = v.Next() {
		for edge := G.GetEdgeList().Front(); edge != nil; edge = edge.Next() {
			a := edge.Value.(*Edge).DestinationVertex.timestamp_d
			b := edge.Value.(*Edge).SourceVertex.timestamp_d
			c := G.GetEdgeWeight(edge.Value.(*Edge).SourceVertex, edge.Value.(*Edge).DestinationVertex)

			if a > b+c {
				edge.Value.(*Edge).DestinationVertex.timestamp_d = b + c
			}

			if edge.Value.(*Edge).DestinationVertex.Predecessor.Len() == 0 {
				edge.Value.(*Edge).DestinationVertex.Predecessor.PushBack(edge.Value.(*Edge).SourceVertex)
			} else {
				pexist := false
				for vtx := edge.Value.(*Edge).DestinationVertex.Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
					if vtx.Value.(*Vertex) == edge.Value.(*Edge).SourceVertex {
						pexist = true
					}
				}

				if pexist == false {
					edge.Value.(*Edge).DestinationVertex.Predecessor.PushBack(edge.Value.(*Edge).SourceVertex)
				}
			}

			if len(edge.Value.(*Edge).DestinationVertex.Prev) == 0 {
				edge.Value.(*Edge).DestinationVertex.Prev = append(edge.Value.(*Edge).DestinationVertex.Prev, edge.Value.(*Edge).SourceVertex)
			} else {
				exist := false
				for _, targetprev := range edge.Value.(*Edge).DestinationVertex.Prev {
					if targetprev == edge.Value.(*Edge).SourceVertex {
						exist = true
					}
				}

				if exist == false {
					edge.Value.(*Edge).DestinationVertex.Prev = append(edge.Value.(*Edge).DestinationVertex.Prev, edge.Value.(*Edge).SourceVertex)
				}
			}
		}
	}

	result_list := list.New()

	for edge := G.EdgeList.Front(); edge != nil; edge = edge.Next() {
		a := edge.Value.(*Edge).DestinationVertex.timestamp_d
		b := edge.Value.(*Edge).SourceVertex.timestamp_d
		c := G.GetEdgeWeight(edge.Value.(*Edge).SourceVertex, edge.Value.(*Edge).DestinationVertex)

		if a > b+c {
			G.TrackBellmanFord(source, target, target, result_list)
			return result_list
		}
	}

	G.TrackBellmanFord(source, target, target, result_list)
	return result_list
}

/*
	Recursive Backtrack needs to check
	0. Be consistent with Stack/Queue order (PushBack, Back, Front)
	1. Exclude the case when we have NON-connected graph (len = 0)
	2. Exclude the case when we get to Source
	3. Check if we still continue recursion
	4. If so, Exclude ENDing Target
	5. If so, Exclude Previously Visited Node
	6. If so, Exclude Duplicate Source Node Visit, caused by concurrent recursion
*/
func (G *Graph) TrackBellmanFord(source, target, end *Vertex, result_list *list.List) {

	result_list.PushFront(target)
	doneWithRecursion := false

	// 1. Exclude the case when we have NON-connected graph (len = 0)
	if target.Predecessor.Len() == 0 {
		doneWithRecursion = true
	}

	// 2. Exclude the case when we get to Source
	if target.Predecessor.Back().Value.(*Vertex) == source {
		doneWithRecursion = true
	}

	fmt.Println("Target:", target.ID, ",", "Predecessor Back():", target.Predecessor.Back().Value.(*Vertex).ID, ",", "Source:", source.ID)

	// 3. Check if we still continue recursion
	if doneWithRecursion == false {
		/*
		   4. If so, Exclude ENDing Target
		   5. If so, Exclude Previously Visited Node
		   6. If so, Exclude Duplicate Source Node Visit, caused by concurrent recursion
		*/

		var newtarget *Vertex
		for vtx1 := target.Predecessor.Back(); vtx1 != nil; vtx1 = vtx1.Prev() {
			newtarget = vtx1.Value.(*Vertex)

			if newtarget == end {
				continue
			}

			texist := false
			// 5. If so, Exclude Previously Visited Node
			for vtx2 := result_list.Front(); vtx2 != nil; vtx2 = vtx2.Next() {
				if newtarget == vtx2.Value.(*Vertex) {
					texist = true
				}

				if source == vtx2.Value.(*Vertex) {
					// we need to skip the case
					// when the recursions visit the source node later
					// which is duplicate
					goto skip
				}
			}

			if texist == true {
				// back to for-loop
				continue
			} else {
				// If neither ENDing Target nor Visited, Run with Recursion
				G.TrackBellmanFord(source, newtarget, end, result_list)
			}
		}
		// 6. If so, Exclude Duplicate Source Node Visit, caused by concurrent recursion
	skip:
	} else {
		result_list.PushFront(source)
		return
	}
}

type Graph struct {
	VertexList *list.List
	EdgeList   *list.List
}

// Construct a new graph and return it.
func NewGraph() *Graph {
	return &Graph{
		list.New(),
		list.New(),
	}
}

type Vertex struct {
	ID    string
	Color string

	EdgesFromThisVertex *list.List

	Predecessor *list.List

	timestamp_d int64

	timestamp_f int64

	Prev []*Vertex
}

func NewVertex(input_id string) *Vertex {
	return &Vertex{
		ID:                  input_id,
		Color:               "white",
		EdgesFromThisVertex: list.New(),
		Predecessor:         list.New(),
		timestamp_d:         9999999999,
		timestamp_f:         9999999999,
		Prev:                nil,
	}
}

type Edge struct {
	SourceVertex      *Vertex
	DestinationVertex *Vertex
	Weight            int64
}

func NewEdge(source, destination *Vertex, weight int64) *Edge {
	return &Edge{
		source,
		destination,
		weight,
	}
}

func (A *Vertex) ConnectEdgeWithVertex(edges ...*Edge) {
	for _, edge := range edges {
		A.EdgesFromThisVertex.PushBack(edge)
	}
}

func (A *Vertex) GetEdgesChannelFromThisVertex() chan *Edge {
	edgechan := make(chan *Edge)

	go func() {
		defer close(edgechan)
		for e := A.EdgesFromThisVertex.Front(); e != nil; e = e.Next() {
			edgechan <- e.Value.(*Edge)
		}
	}()
	return edgechan
}

/*
	Comments on this pattern from Alan Donovan

	While tempting, it's not idiomatic Go style to use channels
	simply for the ability to iterate over them.

	It's not efficient
	, and it can easily lead to an accumulation of idle goroutines:

	consider what happens when the caller of GetEdgesChannelFromThisVertex
	discards the channel before reading to the end.

	---

	It's better to use container/list rather than channel

	Return an adjacent edge list that comes "out of" vertex A.
*/
func (A *Vertex) GetEdgeListFromThisVertex() *list.List {
	return A.EdgesFromThisVertex
}

func (A *Vertex) GetAdjacentVertices() *list.List {
	result := list.New()
	for edge := A.GetEdgeListFromThisVertex().Front(); edge != nil; edge = edge.Next() {
		result.PushBack(edge.Value.(*Edge).DestinationVertex)
	}
	return result
}

func ConstructDirectedGraph(input_str string) *Graph {
	var validID = regexp.MustCompile(`\t{1,}`)
	newstr := validID.ReplaceAllString(input_str, " ")
	newstr = strings.TrimSpace(newstr)
	lines := strings.Split(newstr, "\n")

	new_graph := NewGraph()

	for _, line := range lines {
		fields := strings.Split(line, "|")

		SourceID := fields[0]
		edgepairs := fields[1:]

		new_graph.FindOrConstruct(SourceID)

		for _, pair := range edgepairs {
			if len(strings.Split(pair, ",")) == 1 {
				// to skip the lines below
				// and go back to the for-loop
				continue
			}
			DestinationID := strings.Split(pair, ",")[0]
			weight := StrToInt64(strings.Split(pair, ",")[1])

			src_vertex := new_graph.FindOrConstruct(SourceID)
			des_vertex := new_graph.FindOrConstruct(DestinationID)

			edge := NewEdge(src_vertex, des_vertex, weight)
			src_vertex.ConnectEdgeWithVertex(edge)
			des_vertex.Predecessor.PushBack(src_vertex)

			new_graph.EdgeList.PushBack(edge)
		}
	}
	return new_graph
}
func StrToInt64(input_str string) int64 {
	result, err := strconv.Atoi(input_str)
	if err != nil {
		panic("failed to convert string")
	}
	return int64(result)
}
func (G *Graph) GetVertexByID(id string) *Vertex {
	for vtx := G.VertexList.Front(); vtx != nil; vtx = vtx.Next() {
		// NOT  vtx.Value.(Vertex).ID
		if vtx.Value.(*Vertex).ID == id {
			return vtx.Value.(*Vertex)
		}
	}
	return nil
}

func (G *Graph) FindOrConstruct(id string) *Vertex {
	vertex := G.GetVertexByID(id)
	if vertex == nil {
		vertex = NewVertex(id)

		// then add this vertex to the graph
		G.VertexList.PushBack(vertex)
	}
	return vertex
}

func (G *Graph) GetVertexList() *list.List {
	return G.VertexList
}

func (G *Graph) GetEdgeList() *list.List {
	return G.EdgeList
}

func (G *Graph) DeleteVertex(A *Vertex) {
	for vtx := G.VertexList.Front(); vtx != nil; vtx = vtx.Next() {
		if vtx.Value.(*Vertex) == A {
			// remove from the graph
			G.VertexList.Remove(vtx)
		}
	}

	for edge := A.GetEdgeListFromThisVertex().Front(); edge != nil; edge = edge.Next() {
		G.DeleteEdgeFrom(A, edge.Value.(*Edge).DestinationVertex)
		for vtx := edge.Value.(*Edge).DestinationVertex.Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
			edge.Value.(*Edge).DestinationVertex.Predecessor.Remove(vtx)
		}
	}
}

func (G *Graph) DeleteEdgeFrom(A, B *Vertex) {

	for edge := G.EdgeList.Front(); edge != nil; edge = edge.Next() {

		if edge.Value.(*Edge).SourceVertex == A && edge.Value.(*Edge).DestinationVertex == B {


			
			G.EdgeList.Remove(edge)

			
			for vtx := edge.Value.(*Edge).DestinationVertex.Predecessor.Front(); vtx != nil; vtx = vtx.Next() {
				if vtx.Value.(*Vertex) == A {
					edge.Value.(*Edge).DestinationVertex.Predecessor.Remove(vtx)
				}
			}
		}
	}
}


func (G *Graph) GetVertexSize() int {
	return G.VertexList.Len()
}


func (G *Graph) GetEdgeSize() int {
	return G.EdgeList.Len()
}


func (G *Graph) GetEdgeWeight(source, target *Vertex) int64 {
	for edge := source.GetEdgeListFromThisVertex().Front(); edge != nil; edge = edge.Next() {
		if edge.Value.(*Edge).DestinationVertex == target {
			return edge.Value.(*Edge).Weight
		} else {
			continue
		}
	}
	return 0
}

