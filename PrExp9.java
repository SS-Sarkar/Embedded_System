import java.util.*; 
class PrExp9  
{ 
int[] icode=new int[10];
 double[] iprice=new double[10]; //Execute the Method initialize() 
public void initialize()
 { 
Scanner sc=new Scanner(System.in);
 int i; for(i=0;i<5;i++)
 {
 System.out.print("Enter Item Code  =>");
 icode[i]=sc.nextInt(); 
System.out.print("Enter Item Price =>"); 
iprice[i]=sc.nextDouble(); 
} 
} 
//Execute the Method largest() 
public double largest() 
{ 
double large=iprice[0];
 int i;
 for(i=1;i<5;i++) 
{ 
if (large<iprice[i])  
  large=iprice[i]; 
}   
return large; 
} 
 
//Execute the Method sum() 
public double sum()
 { 
double sum=0; 
int i;
 for(i=0;i<5;i++)
 {
 sum+=iprice[i];
 }  
 return sum; 
} 
//Execute the Method dispitems()
 public void dispitems()
 { 
//int i;
 for(int i=0;i<5;i++)
 {
 System.out.println("Item Code =>"+icode[i]);
 System.out.println("Item Price =>"+iprice[i]);
 } 
  } 
  public static void main(String args[])
 throws IOException { PrExp9 obj=new PrExp9 ();
  obj.initialize();
 double total,big; int ch=0;
 do 
{ 
System.out.println("      MAIN MENU"); 
System.out.println("      =========");
 System.out.println("1. Display the Largest Price");
 System.out.println("2. Display the Sum of Prices");
 System.out.println("3. Display the Item List"); 
System.out.println("For any other Choice except 1/2/3, Exit from the Program"); 
 Scanner sc1=new Scanner(System.in); 
System.out.print("Enter Your Choice(1/2/3) :-");
 ch=sc1.nextInt(); 
switch(ch) 
{
 case 1: big=obj.largest(); 
  System.out.println("The Largest Price is  "+big+"\n");  break; 
case 2: total=obj.sum(); 
  System.out.println("The Sum of Prices =   "+total+"\n");  break; 
case 3: obj.dispitems();  break;
 default:System.out.println("Wrong Choice , Exit from the Program\n");  break; 
 } 
}while(ch>=1&&ch<=3); 
}
 } 