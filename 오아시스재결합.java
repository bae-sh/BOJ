import java.util.*;
public class 오아시스재결합 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		long ans=0;
		Stack<Pair3015> s=new Stack();
		for(int i=0;i<n;i++) {
			Pair3015 p=new Pair3015(a[i], 1);
			while(!s.isEmpty()) {
				if(s.peek().first<=a[i]) {
					ans+=s.peek().second;
					if(s.peek().first==a[i]) {
						p.second+=s.peek().second;
					}
					s.pop();
				}else {
					break;
				}
			}
			if(!s.empty()) ans++;
			s.push(p);
		}
		System.out.println(ans);
		
	}

}
class Pair3015{
	int first,second;
	public Pair3015(int f,int s) {
		this.first=f;
		this.second=s;
	}
}