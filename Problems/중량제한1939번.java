import java.util.*;
public class 중량제한1939번 {
	static int ans=1000000000;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		ArrayList<Pair1939> a[]=new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			a[i]=new ArrayList();
		}
		
		for(int i=0;i<m;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int z=sc.nextInt();
			a[x].add(new Pair1939(y,z));
			a[y].add(new Pair1939(x,z));
		}
		int s=sc.nextInt();
		int e=sc.nextInt();
		int left=1;
		int right=1000000000;
		int ans=0;
		while(left<=right) {
			int mid=left+(right-left)/2;
			boolean check[]=new boolean[n+1];
			if(solve(a,s,e,mid,check)) {
				ans=mid;
				left=mid+1;
			}else {
				right=mid-1;
			}
		}
		System.out.println(ans);
		
	}
	public static boolean solve(ArrayList<Pair1939> a[],int start,int end,int limit,boolean check[]) {
		if(check[start]) {
			return false;
		}
		check[start]=true;
		if(start==end) {
			return true;
		}
		for(int i=0;i<a[start].size();i++) {
			int next=a[start].get(i).y;
			int cost=a[start].get(i).z;
			if(cost>=limit) {
				if(solve(a,next,end,limit,check)) {
					return true;
				}
			}
		}
		return false;
	}
}
class Pair1939{
	int y;
	int z;
	Pair1939(int y,int z){
		this.y=y;
		this.z=z;
	}
}
