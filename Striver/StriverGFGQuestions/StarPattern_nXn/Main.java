
import java.io.*;
import java.util.*;

class Main {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            obj.printSquare(n);
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


class Solution {

    void printSquare(int n) {
        // code here
        StringBuilder sb = new StringBuilder();
        for(int i =0; i<n;i++){
            sb.append("* ");
        }
        String row = sb.toString().trim();
        
        for(int i =0; i<n;i++){
            System.out.println(row);
        }
    }
}