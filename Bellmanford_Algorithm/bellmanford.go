import (
        "fmt"
        "math"
)

func main(){
        /*
        var times =[][]int{ {1,2,1},{2,3,1},{3,4,1}}
        var N, K,g int
        N = 4
        K = 1 
        V :=3
        E :=3*/
        var N,K,g,V,E int
        fmt.Scanf("%d%d",&V,&E)
        //var times[V][E] int
        times :=make([][]int,V,E)
        for i:=0;i<V;i++ {
                var input int;
                for j:=0;j<E;j++ {
                        fmt.Scanf("%d",&input)
                        times[i][j]=input
                }
        }
        fmt.Scanf("%d%d",&N,&K)
        g= BellmanFord(times,N,K,V,E)
        fmt.Printf("Steps needed to reach the destination from vertex %d to vertex %d is %d.\n\n",K,N,g)
        if detectCycle(times, N) {
                fmt.Println("There was a negative cost cycle detected." )
        }else{
                fmt.Println("There was no cycle detected");
        }
}

func detectCycle(a [][]int, N int) bool {
        for i := 0; i < len(a); i++ {
                //for j:=0; j< len(a[i]);j++){
                if a[i][i] < 0 {
                        return true
                }
        }
        return false
}

func BellmanFord(times [][]int, N int, K int, V int, E int) int {
    dist := make([]int, N+1)
    for i, _ := range dist {
        dist[i] = math.MaxInt32
    }
    dist[K] = 0
    for i := 0; i < V ; i++ {
            for j:= 0; j < E; j++ {
            if dist[times[j][0]] + times[j][2] < dist[times[j][1]] {
                dist[times[j][1]] =dist[times[j][0]] + times[j][2]
                }
        }
    }
    fmt.Println("Vertex \t\t Distance from Source")
    for i :=1; i<=N; i++ {
        fmt.Printf("%d \t\t %d\n",i,dist[i]);
    }
    fmt.Println()
    
    maxWait := 0
    
    for x := 1; x <= N; x++ {
        maxWait = int(math.Max(float64(maxWait), float64(dist[x])))
    }
    
    if maxWait != math.MaxInt32 {
        return maxWait
    } else {
        return -1
    }
    
}

