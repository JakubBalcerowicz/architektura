import java.io.*;

class Pesel{
  String pesel;

  Pesel(String pes){

   pesel = pes;
  }
  int at(int n){
  return Character.getNumericValue(pesel.charAt(n));
  }
  boolean valid(){

   //int c=pesel.charAt(2);  //zamian zmiennej string na liczbe
   int c = 0;
   c = at(2);
   //c = Character.getNumericValue(pesel.charAt(2));
   System.out.println(pesel +", "+c);
   return false;

  }





  public static void main(String[] args) {

  //System.out.println(args[0]);
   
  Pesel p = new Pesel( args[0]);
  if(p.valid() )
  System.out.println("ok");
  else
  System.out.println("nieok");

  }
}
