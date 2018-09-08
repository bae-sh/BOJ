package 백준;

import java.util.*;
import java.io.*;
public class 접미사배열 {

	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		char[] n=br.readLine().toCharArray();
		
		ArrayList ar= new ArrayList();
		for(int i=0;i<n.length;i++) {
			String x="";
			for(int j=i;j<n.length;j++) {
				x+=n[j];
			}
			ar.add(x);
		}
		Collections.sort(ar);
		Iterator it = ar.iterator();
		while(it.hasNext()) {
			System.out.println(it.next());
		}

	}

}
