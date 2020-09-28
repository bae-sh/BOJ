import java.util.*;

public class 수묶기1744번  {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int ans=0;
		ArrayList<Integer> p=new ArrayList<>();
		ArrayList<Integer> m=new ArrayList<>();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			if(a>0)
				p.add(a);
			else if(a<=0)
				m.add(a);
		}
		Collections.sort(p,Collections.reverseOrder());
		Collections.sort(m);
		for(int i=0;i<p.size();i+=2) {
			if(i==p.size()-1&&i%2==0) {
				ans+=p.get(i);
			}
			else {
				if(p.get(i)==1)
					ans+=2;
				else if(p.get(i+1)==1)
					ans+=p.get(i)+1;
				else
					ans+=p.get(i)*p.get(i+1);
			}
		}
		for(int i=0;i<m.size();i+=2) {
			if(i==m.size()-1&&i%2==0) {
				ans+=m.get(i);
			}
			else {
				ans+=m.get(i)*m.get(i+1);
			}
		}
		System.out.println(ans);
	}
}
