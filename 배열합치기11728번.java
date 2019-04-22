import java.io.*;
import java.util.*;

public class 배열합치기11728번 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.valueOf(line[0]);
        int m = Integer.valueOf(line[1]);
        int[] a = new int[n];
        line = br.readLine().split(" ");
        for (int i=0; i<n; i++) {
            a[i] = Integer.valueOf(line[i]);
        }
        int[] b = new int[m];
        line = br.readLine().split(" ");
        for (int i=0; i<m; i++) {
            b[i] = Integer.valueOf(line[i]);
        }
        int[] c = new int[n+m];
        {
            int i = 0;
            int j = 0;
            int k = 0;
            while (i < n || j < m) {
                if (j >= m || (i < n && a[i] <= b[j])) {
                    c[k++] = a[i++];
                } else {
                    c[k++] = b[j++];
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<n+m; i++) {
            sb.append(c[i] + " ");
        }
        System.out.println(sb);
    }
}