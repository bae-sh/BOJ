import java.util.*;
public class 과자 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		int n=sc.nextInt();
		int m=sc.nextInt();
		
		int ans=(n*k)-m;
		if(ans<=0) {
			System.out.println(0);
		}else {
			System.out.println(ans);
		}
	}

}
