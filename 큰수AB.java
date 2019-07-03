import java.util.*;
public class 큰수AB {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		boolean p=false;
		StringBuilder sb=new StringBuilder();
		int x[]=new int[10001];
		int y[]=new int[10001];
		int ans[]=new int[10002];
		for(int i=a.length()-1;i>=0;i--) {
			x[a.length()-1-i]=Integer.parseInt(a.charAt(i)+"");
		}
		for(int i=b.length()-1;i>=0;i--) {
			y[b.length()-1-i]=Integer.parseInt(b.charAt(i)+"");
		}
		for(int i=0;i<10001;i++) {
			int n=x[i]+y[i]+ans[i];
			ans[i]=n%10;
			ans[i+1]=n/10;
		}
		for(int i=10001;i>=0;i--) {
			if(ans[i]==0&&!p) {
				continue;
			}else {
				p=true;
				sb.append(ans[i]);
			}
		}
		System.out.println(sb.toString());
	}

}
