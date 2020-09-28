import java.util.*;
public class 스타트와링크 {
	static int ans=1000000000;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int d[][]=new int[n][n];
		int arr[]=new int[n/2];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				int x=sc.nextInt();
				d[i][j]=x;
			}
		}
		combi(arr,1,n-1,n/2-1,1,d);
		System.out.println(ans);
		
	}
	static void combi(int[] arr,int index,int n,int r,int target,int d[][]) {
		if(r==0) {
			boolean b[]=new boolean[arr.length*2];
			for(int i=0;i<arr.length;i++) {
				b[arr[i]]=true;
			}
			int s1=0;int s2=0;
			for(int i=0;i<b.length;i++) {
				for(int j=0;j<b.length;j++) {
					if(b[i]&&b[j]) {
						s1+=d[i][j];
					}else if(!b[i]&&!b[j]) {
						s2+=d[i][j];
					}
				}
			}
			ans=Math.min(ans, Math.abs(s1-s2));
		}else if(target==n+1){
			return;
		}else {
		
			arr[index]=target;
			combi(arr,index+1,n,r-1,target+1,d);
			combi(arr,index,n,r,target+1,d);
		}
	}

}
