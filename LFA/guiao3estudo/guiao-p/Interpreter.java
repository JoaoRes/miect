import java.util.HashMap;
import java.util.Scanner;

public class Interpreter extends StrLangMainBaseVisitor<String> {

   HashMap<String, String> variables = new HashMap<>();
   HashMap<String, HashMap<String, String>> renderizer = new HashMap<>();
   //        t1            <name>, "Manel" 

   @Override public String visitProgram(StrLangMainParser.ProgramContext ctx) {
      return visitChildren(ctx);
   }

   @Override public String visitStat(StrLangMainParser.StatContext ctx) {
      return visitChildren(ctx);
   }

   @Override public String visitAssignment(StrLangMainParser.AssignmentContext ctx) {
      String id= ctx.ID().getText();
      if(variables.containsKey(id)){
         System.err.println("ERROR: variable already exists");
         System.exit(-1);
      }
      variables.put(id, visit(ctx.expression()));
      HashMap<String, String> aux = new HashMap<>();
      renderizer.put(visit(ctx.expression()), aux);
      return null;
   }

   @Override public String visitExprInput(StrLangMainParser.ExprInputContext ctx){
      Scanner sc = new Scanner(System.in);
      System.out.println(ctx.STRING().getText());
      return sc.next();
   }

   @Override public String visitExprParent(StrLangMainParser.ExprParentContext ctx) {
      return visit(ctx.expression());
   }

   @Override public String visitExprAdd(StrLangMainParser.ExprAddContext ctx) {
      String variavel = visit(ctx.expression(2));
      String subs = visit(ctx.expression(1));
      String name = visit(ctx.expression(0));
      
      if(renderizer.containsKey(variavel)){
         if(variavel.contains(subs)){
            String x="";
            if(renderizer.get(variavel).get(subs)!=null){
               x=renderizer.get(variavel).get(subs) + " " + name;
            }else{
               x=name;
            }
            renderizer.get(variavel).put(subs, x);
         }else{
            System.err.println("ERROR: " + subs+ "doesnt exists in " + variavel);
            System.exit(-1);
         }
      }else{
         System.err.println("ERROR: " + variavel + "doesnt exists");
         System.exit(-1);
      }

      return null;
   }

   @Override public String visitExprRender(StrLangMainParser.ExprRenderContext ctx) {
      String str = visit(ctx.expression());
      if(renderizer.containsKey(str)){
         for(String x : renderizer.get(str).keySet()){
            String a = renderizer.get(str).get(x);
            str = str.replaceAll(x , a);
         }    
      }
      System.out.println(str);
      return null;
   }

   @Override public String visitExprReplace(StrLangMainParser.ExprReplaceContext ctx) {
      String str1 = visit(ctx.expression(0));
      String str2 = visit(ctx.expression(1));
      String str3 = visit(ctx.expression(2));
      
      return str1.replaceAll(str2, str3);
   }

   @Override public String visitExprConcat(StrLangMainParser.ExprConcatContext ctx) {
      String str1 = visit(ctx.expression(0));
      String str2 = visit(ctx.expression(1));

      String res = str1 + str2 ;

      return res;
   }

   @Override public String visitExprString(StrLangMainParser.ExprStringContext ctx) {
      String str =ctx.STRING().getText();
      if(str.equals("")){
         System.err.println("ERROR: empty string");
         System.exit(-1);
      }
      return str.substring(1, str.length()-1 );

   }

   @Override public String visitExprID(StrLangMainParser.ExprIDContext ctx) {
      String id= ctx.ID().getText();
      if(variables.containsKey(id)){
         return variables.get(id);
      }else{
         System.err.println("ERROR: variavel nao existente");
         System.exit(-1);
      }
      return id;
   }

   @Override public String visitPrint(StrLangMainParser.PrintContext ctx) {
      System.out.println(visit(ctx.expression()));
      return null;
   }
}
