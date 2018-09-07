package 백준;

import java.util.Scanner;

public class 수정렬하기11931 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x[] = new int[n];
		for(int i=0;i<n;i++) {
			x[i]=sc.nextInt();
		}
		sort(x,0,x.length-1);
		for(int i=n-1;i>=0;i--) {
		System.out.println(x[i]);}
	}
	public static void sort(int data[],int l,int r) {
		int left = l;
		int right = r;
		int pivot = data[(l+r)/2];
		
		do {
			while(data[left]<pivot) left++;
			while(data[right]>pivot) right--;
			if(left<=right) {
				int temp = data[left];
				data[left]=data[right];
				data[right]=temp;
				left++;
				right--;
			}
		}while(left<=right);
		if(l<right) sort(data,l,right);
		if(r>left) sort(data,left,r);
	}
}
