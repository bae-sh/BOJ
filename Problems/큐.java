package 백준;

import java.io.*;
import java.util.*;
public class 큐 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Queue q = new LinkedList();
		
		int n=Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			String[] a=br.readLine().split(" ");
			if(a[0].equals("push")) {
				q.offer(Integer.parseInt(a[1]));
			}
			else if(a[0].equals("pop")) {
				if(q.isEmpty()) {
					System.out.println(-1);
				}
				else
				System.out.println(q.poll());
			}
			else if(a[0].equals("size")) {
				System.out.println(q.size());
			}
			else if(a[0].equals("empty")) {
				if(q.isEmpty()) {
					System.out.println(1);
				}
				else
					System.out.println(0);
			}
			else if(a[0].equals("front")) {
				if(!q.isEmpty()) {
					System.out.println(q.peek());
				}
				else 
					System.out.println(-1);
			}
			else if(a[0].equals("back")) {
				int s=q.size();
				if(q.isEmpty()) {
					System.out.println(-1);
				}
				else {
				for(int j=0;j<s;j++) {
					if(j==s-1) {
						System.out.println(q.peek());
					}
						q.offer(q.poll());
				}
				}
			}
		}
	}

}
