import java.util.*;
public class 사다리2022번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		double x=sc.nextDouble();
		double y=sc.nextDouble();
		double h=sc.nextDouble();
		
		double l=0;
		double r=Math.min(x, y);
		double mid=0;
		while(Math.abs(r-l)>1e-6) {
			mid=(l+r)/2;
			
			double ans=1/h-1/Math.sqrt(x*x-mid*mid)-1/Math.sqrt(y*y-mid*mid);
			if(ans>0) {
				l=mid;
			}else {
				r=mid;
			}
		}
		System.out.println(String.format("%.3f", mid));
		
	}

}
