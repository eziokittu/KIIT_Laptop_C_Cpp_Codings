import java.util.*;

public class test {
  // Overloaded method with no arguments
  public static void p() {
    p("", 0);
  }

  // Overloaded method with one String argument
  public static void p(String s) {
    p(s, 0);
  }

  // Overloaded method with one int argument
  public static void p(int a) {
    p("", a);
  }

  // Method with both String and int arguments
  public static void p(String s, int a) {
    System.out.println(s + " " + a);
  }

  public static void main(String[] args) {
    // Scanner sc = new Scanner(System.in);
    // System.out.print("Enter a string: ");
    // String input = sc.nextLine();
    // input+="hello";
    // System.out.println(input);
    // sc.close();
    // int[] arr = {2,6,1,9,3};
    // Arrays.sort(arr);
    // for (int i=0; i<arr.length; i++){
    //   System.out.print(arr[i]+" ");
    // }
    p("this is", 4);
    // System.out.println(60.3 - (int)60.3); // 0.29999999999999716
  }
}