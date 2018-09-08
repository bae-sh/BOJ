package 백준;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class 에디터 {

	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s=br.readLine();
		int n= Integer.parseInt(br.readLine());
		Stack left=new Stack();
		Stack right=new Stack();
		for(int i=0;i<s.length();i++) {
			left.push(s.charAt(i));
		}
		for(int i=0;i<n;i++) {
			String[] x = br.readLine().split(" ");
			
			if(x[0].equals("P")) {
				String y=x[1];
				left.push(y);
			}
			else if(x[0].equals("L")) {
				if(!left.empty())
				right.push(left.pop());
			}
			else if(x[0].equals("D")) {
				if(!right.empty())
				left.push(right.pop());
			}
			else if(x[0].equals("B")) {
				if(!left.empty()) {
					left.pop();
				}
			}
		}
		while(!left.empty()) {
			right.push(left.pop());
		}
		int k=right.size();
		
		for(int i=0;i<k;i++) {
			System.out.print(right.pop());
		}
		
	}

}
