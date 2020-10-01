var nodes = [
    {
        links: [1, 2, 3],
        visited: false
    },
    {
        links: [4, 5],
        visited: false
    },
    {
        links: [],
        visited: false
    },
    {
        links: [6, 7],
        visited: false
    },
    {
        links: [],
        visited: false
    },
    {
        links: [],
        visited: false
    },
    {
        links: [],
        visited: false
    },
    {
        links: [],
        visited: false
    }
];

function bfs(start) {
    var queue = [start];
    nodes[start].visited = true;
    while (queue.length > 0) {
        var node = queue.shift();
        console.log(node);
        nodes[node].links.forEach(node => {
            if (!node.visited) {
                nodes[node].visited = true;
                queue.push(node);
            }
        });
    }
}
bfs(0);
/* output
0
1
2
3
4
5
6
7*/
