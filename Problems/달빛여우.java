package 백준;
import java.util.*;
class Pair3{
	int x;
	int y;
	Pair3(int x,int y){
		this.x=x;
		this.y=y;
	}
}
public class 달빛여우 {
	static ArrayList<Pair3> a[];
	static void bfs(ArrayList<Pair3> a[],int f[],int w[],int b) {
		Queue<Pair3> q=new LinkedList<Pair3>();
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int f[]=new int[n+1];//여우
		int w[]=new int[n+1];//울프
		a=(ArrayList<Pair3>[])new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			a[i]=new ArrayList<Pair3>();
		}
		for(int i=1;i<=m;i++) {
			int b=sc.nextInt();
			int x=sc.nextInt();
			int y=sc.nextInt();
			a[b].add(new Pair3(x,y));
		}
	}

}
