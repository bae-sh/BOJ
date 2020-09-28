package 백준;

import java.util.*;
public class 반복수열2331번 {
	static void dfs(int c[],int x,int count,int p) {
		String s=Long.toString(x);
		int y=0;
		c[x]=count;
		for(int j=0;j<s.length();j++) {
			int q=s.charAt(j)-'0';
			y+=Math.pow(q, p);
		}
		if(c[y]!=0) {
			System.out.println(c[y]-1);
			return;
		}
		else {
			count++;
			c[y]=count;
			dfs(c,y,count,p);
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int p=sc.nextInt();
		int c[]=new int[2000000];
		dfs(c,n,1,p);
		
	}

}
