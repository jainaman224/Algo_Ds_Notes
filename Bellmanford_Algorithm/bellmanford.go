package main

import (
	"container/list"
	"fmt"
	"regexp"
	"strconv"
	"strings"
)

func main() {

	

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


func (G *Graph) TrackBellmanFord(source, target, end *Vertex, result_list *list.List) {

	result_list.PushFront(target)
	doneWithRecursion := false

	
	if target.Predecessor.Len() == 0 {
		doneWithRecursion = true
	}

	
	if target.Predecessor.Back().Value.(*Vertex) == source {
		doneWithRecursion = true
	}

	fmt.Println("Target:", target.ID, ",", "Predecessor Back():", target.Predecessor.Back().Value.(*Vertex).ID, ",", "Source:", source.ID)

	
	if doneWithRecursion == false {
		

		var newtarget *Vertex
		for vtx1 := target.Predecessor.Back(); vtx1 != nil; vtx1 = vtx1.Prev() {
			newtarget = vtx1.Value.(*Vertex)

			if newtarget == end {
				continue
			}

			texist := false
			for vtx2 := result_list.Front(); vtx2 != nil; vtx2 = vtx2.Next() {
				if newtarget == vtx2.Value.(*Vertex) {
					texist = true
				}

				if source == vtx2.Value.(*Vertex) {
					
					goto skip
				}
			}

			if texist == true {
				continue
			} else {
				G.TrackBellmanFord(source, newtarget, end, result_list)
			}
		}
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

