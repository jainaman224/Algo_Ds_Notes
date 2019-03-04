//Topological Sort using Java (Adjacency Matrix Representation)
package topo_sort;

import java.util.Scanner;

class topo_sort 
{
	public static void main(String args[])
	{
		graph g=new graph(5);
		
		g.accept(0, 1);
		g.accept(1, 3);
		g.accept(0, 2);
		g.accept(0, 3);
		g.accept(2, 3);
		g.accept(4, 1);
		
		/*
		  
		  0->1<-4
		  |\ |
		  | \|
		  2->3
		  
		  
		 */
		
		g.topo();
	}
}

class graph
{
	int e, v;							//e-no of edges, v-no of vertices
	int matrix[][]=new int[40][40];		//to make adjacency matrix
	int toposort[]=new int[40];
	int vertex[]=new int[40];
	
	
	//default constructor
	graph(int ver)
	{
		v=ver;
		//System.out.println("Reached here");
		for(int i=0; i<ver; i++)
		{
			vertex[i]=i;
		}
		
		for(int i=0; i<ver; i++)
		{
			for(int j=0; j<ver; j++)
			{
				matrix[i][j]=0;
			}
		}
	}
	
	Scanner s=new Scanner(System.in);
	
	//accept all edges and vertices
	void accept(int a, int b)
	{
		matrix[b][a]=1;
	}
	
	void topo()
	{
		int original=v;
		int index=0;
		while(v>0)
		{
			int thisvertex=nosuccessor();	//returns vertex with degree 0
			if(thisvertex==-1)
			{
				System.out.println("Graph is cyclic");
				return;
			}
			
			toposort[index]=vertex[thisvertex];
			index++;
			//delete this vertex from graph
			deleteVertex(thisvertex);
		}
		
		
		//display sorted array
		for(int i=0; i<original; i++)
		{
			System.out.print(toposort[i]+" ");
		}
	}
	
	int nosuccessor()
	{
		int flag;
		for(int i=0; i<v; i++)
		{
			flag=0;
			for(int j=0; j<v; j++)
			{
				if(matrix[i][j]!=0)		//i.e. edge exists
				{
					flag=1;	
					break;
				}
			}
			if(flag==0)
				return i;
		}
		
		return -1;					//if no such edge
	}
	
	void deleteVertex(int x)
	{
		//if not the last vertex
		if(x!=v-1)
		{
			//shifted all vertices remaining, appropriately
			for(int i=x; i<v; i++)
			{
				vertex[i]=vertex[i+1];
			}
			
			//moved remaining rows up in the adjacency matrix
			for(int i=x; i<v; i++)
			{
				moveRowUp(i, v);
			}
			
			//moved remaining columns left in the adjacency matrix
			for(int j=x; j<v; j++)
			{
				moveColumnLeft(j, v);
			}	
		}
		v--;		//reduced v, thus while loop will have appropriate condition
	}
	
	//moved remaining rows up in the adjacency matrix
	void moveRowUp(int i, int v)
	{
		for(int j=0; j<v; j++)
		{
			matrix[i][j]=matrix[i+1][j];
		}
	}
	
	//moved remaining columns left in the adjacency matrix
	void moveColumnLeft(int j, int v)
	{
		for(int i=0; i<v; i++)
		{
			matrix[i][j]=matrix[i][j+1];
		}
	}
}

//Output
//0 2 4 1 3
