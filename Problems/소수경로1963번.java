import java.util.*;
public class 소수경로1963번 {
	static int ans;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.nextLine();
		boolean c[]=new boolean[10000];
		for(int i=2;i<10000;i++) {
			if(c[i]==false) {
				for(int j=i*i;j<10000;j+=i) {
					c[j]=true;
				}
			}
		}
		for(int i=0;i<n;i++) {
			String s[]=sc.nextLine().split(" ");
			if(s[0].equals(s[1])) {
				System.out.println(0);
				continue;
			}
			int check[]=new int[10000];
			ans=Integer.parseInt(s[1]);
			Queue<Integer> q=new LinkedList();
			q.add(Integer.parseInt(s[0]));
			while(!q.isEmpty()) {
				int x=q.remove();
				for(int j=0;j<4;j++) {
					for(int k=0;k<10;k++) {
						change(x,j,k,q,c,check);
					}
				}
			}
			if(check[ans]!=0) {
				System.out.println(check[ans]);
			}else
			System.out.println("Impossible");
		}
		
	}
	public static void change(int x,int index,int k,Queue<Integer> q,boolean ce[],int check[]) {
		StringBuilder sb=new StringBuilder(x+"");
		char c=(char)(k+'0');
		int b=Integer.parseInt(sb.toString());
		sb.setCharAt(index, c);
		int a=Integer.parseInt(sb.toString());
		if(a>=1000&&ce[a]==false&&check[a]==0&&a!=b) {
			check[a]=check[b]+1;
			q.add(a);
		}
	}

}
