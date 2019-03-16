import java.util.ArrayList;

public class Z {
    private String P;
    private String T;
    private int[] Z;
    private ArrayList<Integer> match_pos = new ArrayList<Integer>();

    public void calculateZ(String P) {
	int n = P.length();
	Z = new int[n];

	int L, R, k;
	L = R = 0;
	for (int i=1; i<n; i++) {
	    if (i >= R) {
		L = R = i;
		while(R<n && P.charAt(R-L) == P.charAt(R))
		    R++;
		Z[i] = R-L;
	    } else {
		k = i - L;
		if (Z[k] < R-i+1) {
		    Z[i] = Z[k];
		} else {
		    L = i;
		    while(R<n && P.charAt(R-L) == P.charAt(R))
			R++;
		    Z[i] = R-L;
		}
	    }
	}
	
    }

    public int[] getZ() {
	return Z;
    }
    
    public void search(String T, String P) {
	this.P = P;
	this.T = T;
	int n = P.length();

	String S = P + "$" + T;
	calculateZ(S);
	for (int i = 0; i<S.length(); i++) {
	    if (Z[i] == n) 
		match_pos.add(i-n-1);
	}
    }
    
    public void printPos() {
	for (int i=0; i<match_pos.size(); i++) {
	    System.out.println(match_pos.get(i));
	}
    }

    

    public void printMatchPosition() {
	MatchPosition mp = new MatchPosition(T, P, match_pos);
	mp.print();
    }

}

