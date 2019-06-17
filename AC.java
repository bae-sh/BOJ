import java.util.*;
import java.io.*;
public class AC {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		 int t=Integer.parseInt(br.readLine());
		 StringBuilder an=new StringBuilder();
		 while(t-->0) {
			 String p[]=br.readLine().split("");
			 int n=Integer.parseInt(br.readLine());
			 Deque dq=new LinkedList();
			 String s=br.readLine();
			 StringTokenizer stk = new StringTokenizer(s,"[,]");
			 StringBuilder sb=new StringBuilder();
			 boolean er=false;
			 while(stk.hasMoreTokens()) {
				 dq.add(stk.nextToken());
			 }
			 boolean r=true;
			 for(int i=0;i<p.length;i++) {
				 if(p[i].equals("R")) {
					 r=!r;
				 }else {
					 if(dq.isEmpty()) {
						 sb.append("error");
						 if(t!=0) {
							 sb.append("\n");
						 }
						 an.append(sb);
						 er=true;
						 break;
					 }
					 else if(r) {
						 dq.poll();
					 }else {
						 dq.pollLast();
					 }
				 }
			 }
			 sb.append("[");
			 while(!dq.isEmpty()) {
				 if(r) {
					 sb.append(dq.poll());
				 }else {
					 sb.append(dq.pollLast());
				 }
				 if(!dq.isEmpty()) {
					 sb.append(",");
				 }
			 }
			 if(!er) {
				 sb.append("]");
				 if(t!=0) {
					 sb.append("\n");
				 }
				 an.append(sb);
			 }
		 }
		 System.out.print(an.toString());
	}

}
