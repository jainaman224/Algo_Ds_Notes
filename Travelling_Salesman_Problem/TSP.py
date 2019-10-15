V = 4
answer = [] 
  

def tsp(graph, v, currPos, n, count, cost): 
  
    
    if (count == n and graph[currPos][0]): 
        answer.append(cost + graph[currPos][0]) 
        return
  
    # BACKTRACKING STEP 
   
    for i in range(n): 
        if (v[i] == False and graph[currPos][i]): 
              
            # Mark as visited 
            v[i] = True
            tsp(graph, v, i, n, count + 1,  
                cost + graph[currPos][i]) 
              
            # Mark ith node as unvisited 
            v[i] = False
  


if __name__ == '__main__': 
    n = 4
    graph= [[ 0, 10, 15, 20 ], 
            [ 10, 0, 35, 25 ], 
            [ 15, 35, 0, 30 ], 
            [ 20, 25, 30, 0 ]] 
  
    
    v = [False for i in range(n)] 
      
    
    v[0] = True
  
   
    tsp(graph, v, 0, n, 1, 0) 
  
    
    print(min(answer)) 
