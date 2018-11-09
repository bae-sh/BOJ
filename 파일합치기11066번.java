package 백준;
import java.util.*;
public class 파일합치기11066번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int k=sc.nextInt();
			int cnt=1;
			int ans=0;
			int mini=k;
			int d[]=new int[k];
			for(int j=0;j<k;j++) {
				d[j]=sc.nextInt();
			}
			
			while(d[1]!=0) {
				for(int j=0;j<mini;j++) {
					if(d[j]==0) {
						d[j]=d[j+1];
						d[j+1]=0;
						mini-=1;
					}
				}
				int min=d[0]+d[1];
				for(int j=0;j<mini-1;j++) {
					if(min>d[j]+d[j+1]) {
						min=d[j]+d[j+1];
						cnt=j;
					}
				}
				d[cnt]=d[cnt]+d[cnt+1];
				d[cnt+1]=0;
				ans+=d[cnt];
			}
			System.out.println(ans);
		}
	}

}
