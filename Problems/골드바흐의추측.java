import java.util.*;
public class 골드바흐의추측 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		boolean b[]=new boolean[10001];
		for(int i=2;i<=100;i++) {
			if(b[i]==false) {
				for(int j=i*i;j<10001;j+=i) {
					b[j]=true;
				}
			}
		}
		while(t-->0) {
			int n=sc.nextInt();
			int left=n/2,right=n/2;
			while(true) {
				if(!b[left]&&!b[right]) {
					System.out.println(left+" "+right);
					break;
				}else {
					left--;right++;
				}
			}
		}
	}

}
