import java.util.*;
import java.io.*;
public class 히스토그램6549 {
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		while(true) {
			String[] s=br.readLine().split(" ");
			int d[]=new int[Integer.parseInt(s[0])];
			Stack<Integer> st=new Stack<>();
			int right=0;
			int left=0;
			long ans=0;
			
			if(d.length==0) {
				break;
			}else {
				for(int i=0;i<d.length;i++) {
					d[i]=Integer.parseInt(s[i+1]);
				}
				
				for(int i=0;i<d.length;i++) {
					if(st.isEmpty()||d[st.peek()]<=d[i]) {
						st.push(i);
					}else{
						int t=st.pop();
						right=i-1;
						int k=st.size()-1;
						for(int j=k;j>=0;j--) {
							left=j;
							if(d[j]<d[t]) {
								ans=Math.max(ans, d[t]*(right-left));
								break;
							}
						}
					}
				}
				
			}
		}
		
	}

}
