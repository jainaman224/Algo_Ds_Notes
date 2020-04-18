class Edge
  attr_accessor :node1, :node2, :weight

  def initialize(node1, node2, weight)
    @node1, @node2, @weight = node1, node2, weight
  end

  def <=>(other)
    self.weight <=> other.weight
  end

  def to_s
    "#{node1.to_s} <=> #{node2.to_s} with weight #{weight}"
  end
end

class Graph
  attr_accessor :nodes
  attr_accessor :edges

  def initialize
    @nodes = []
    @edges = []
  end

  def add_node(node)
    nodes << node
    node.graph = self
  end

  def add_edge(from, to, weight)
    edges << Edge.new(from, to, weight)
  end
end

class UnionFind
  def initialize(nodes)
    @unions = {}
    nodes.each_with_index do |node, index|
      @unions[node] = index
    end
  end

  def connected?(node1, node2)
    @unions[node1] == @unions[node2]
  end

  def union(node1, node2)
    return if connected?(node1, node2)
    node1_id = @unions[node1]
    node2_id = @unions[node2]

    @unions.each do |node, id|
      @unions[node] = node1_id if id == node2_id
    end
  end
end

class Kruskal
  def compute_mst(graph)
    mst = []
    edges = graph.edges.sort!

    union_find = UnionFind.new(graph.nodes)
    while edges.any? && mst.size <= graph.nodes.size
      edge = edges.shift
      if !union_find.connected?(edge.node1, edge.node2)
        union_find.union(edge.node1, edge.node2)
        mst << edge
      end
    end

    mst
  end
end

class Node
  attr_accessor :name, :graph

  def initialize(name)
    @name = name
  end

  def adjacents
    graph.edges.select { |e| e.from == self }.map(&:to)
  end

  def to_s
    @name
  end
end

graph = Graph.new

graph.add_node(node0 = Node.new("Node #0"))
graph.add_node(node1 = Node.new("Node #1"))
graph.add_node(node2 = Node.new("Node #2"))
graph.add_node(node3 = Node.new("Node #3"))
graph.add_node(node4 = Node.new("Node #4"))
graph.add_node(node5 = Node.new("Node #5"))
graph.add_node(node6 = Node.new("Node #6"))
graph.add_node(node7 = Node.new("Node #7"))

graph.add_edge(node0, node7, 16)
graph.add_edge(node2, node3, 17)
graph.add_edge(node1, node7, 19)
graph.add_edge(node0, node2, 26)
graph.add_edge(node5, node7, 28)
graph.add_edge(node1, node3, 29)
graph.add_edge(node1, node5, 32)
graph.add_edge(node2, node7, 34)
graph.add_edge(node4, node5, 35)
graph.add_edge(node1, node2, 36)
graph.add_edge(node4, node7, 37)
graph.add_edge(node0, node4, 38)
graph.add_edge(node6, node2, 40)

pp Kruskal.new.compute_mst(graph).map(&:to_s)
