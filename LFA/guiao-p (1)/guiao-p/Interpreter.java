import java.util.*;

public class Interpreter extends StrLangMainBaseVisitor<String> {

   HashMap<String, String> variables = new HashMap<>();

   @Override public String visitProgram(StrLangMainParser.ProgramContext ctx) {
      return visitChildren(ctx);
   }

   @Override public String visitStat(StrLangMainParser.StatContext ctx) {
      return visitChildren(ctx);
   }

   @Override public String visitAssignment(StrLangMainParser.AssignmentContext ctx) {
      if(variables.containsKey(ctx.ID().getText())){
         System.err.println("ERROR: Variable already exists");
      }else{
         variables.put(ctx.ID().getText(), visit(ctx.expression()));
      }
      return null;
   }

   @Override public String visitExprParent(StrLangMainParser.ExprParentContext ctx) {
      return visit(ctx.expression());
   }
   
   @Override public String visitExprInput(StrLangMainParser.ExprInputContext ctx) {
      Scanner sc = new Scanner(System.in);
      String res;
      System.out.print(ctx.STRING().getText() + " ");
      res= sc.next();
      return res;
   }

   @Override public String visitExprConcat(StrLangMainParser.ExprConcatContext ctx){
      String str1 = visit(ctx.expression(0));
      String str2 = visit(ctx.expression(1));

      return str1.concat(str2);
   }

   @Override public String visitExprString(StrLangMainParser.ExprStringContext ctx) {
      String res = ctx.STRING().getText();
      return res.substring(1, res.length()-1);
   }

   @Override public String visitExprSubs(StrLangMainParser.ExprSubsContext ctx){
      String str1 = visit(ctx.expression(0));
      String str2 = visit(ctx.expression(1));
      String str3 = visit(ctx.expression(2));

      return str1.replaceAll(str2, str3);

   }

   @Override public String visitExprID(StrLangMainParser.ExprIDContext ctx) {
      String res = ctx.ID().getText();
      if(variables.containsKey(res)){
         return variables.get(res);
      }else{
         System.err.println("ERROR: Variavel nao definida");
         System.exit(-1);
      }
      return res;
   }

   @Override public String visitPrint(StrLangMainParser.PrintContext ctx) {
      System.out.println(visit(ctx.expression()));
      return null;
   }
}
