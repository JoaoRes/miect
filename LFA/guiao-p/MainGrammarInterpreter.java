import java.util.HashMap;

public class MainGrammarInterpreter extends MaingrammarBaseVisitor<String> {

   private HashMap<String, String> MapaStrings = new HashMap<>();

   @Override public String visitDeclaration(MaingrammarParser.DeclarationContext ctx) {
      String var = ctx.var.getText();
      String string = ctx.expression().getText();
      
      if(!MapaStrings.containsKey(var)){
         MapaStrings.put(var, string);
         return string;
      }else{
         System.err.println("ERROR: Variable already exists");
         return string;
      }  
   }

   @Override public String visitStringExpr(MaingrammarParser.StringExprContext ctx) {
      String string = ctx.String().getText();
      if(MainGrammarParser.MapaStrings.containsKey(string)) string = MainGrammarParser.MapaStrings.get(string);
      return string;
   }

   @Override public String visitInputExpr(MaingrammarParser.InputExprContext ctx) {
      String string = ctx.expression().getText();
      return null;
   }

   @Override public String visitSubExpr(MaingrammarParser.SubExprContext ctx) {
      return visitChildren(ctx);
   }

   @Override public String visitParentExpr(MaMainGrammarParser.MapaStrings.ingrammarParser.ParentExprContext ctx) {
      return visit(ctx.expression());
   }

   @Override public String visitSumExpr(MaingrammarParser.SumExprContext ctx) {
      String str1 = visit(ctx.e1);
      String str2 = visit(ctx.e2);

      if(MaingrammarParser.MapaStrings.containsKey(str1))

      String str3 = str1.replaceAll("\\s", "") + str2.replaceAll("\\s", "");
      
      return str3;
   }
                                                     
   @Override public String visitPrint(MaingrammarParser.PrintContext ctx) {
      String string = ctx.expression().getText();
      System.out.println(string);
      return null;
   }
}
