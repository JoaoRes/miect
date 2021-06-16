public class Interpreter extends SuffixCalculatorBaseVisitor<Double> {

   @Override public Double visitProgram(SuffixCalculatorParser.ProgramContext ctx) {
      return visitChildren(ctx);
   }

   @Override public Double visitStat(SuffixCalculatorParser.StatContext ctx) {
      return visitChildren(ctx);
   }

   @Override public Double visitExprNumber(SuffixCalculatorParser.ExprNumberContext ctx) {
      return Double.parseDouble(ctx.NUMBER().getText());
     }

   @Override public Double visitExprSuffix(SuffixCalculatorParser.ExprSuffixContext ctx) {
      double e1= visit(ctx.expr(0));
      double e2= visit(ctx.expr(1));
      double res=0;
      if(ctx.op.getText().equals("+")){
         res= e1+e2;
         System.out.println(res);
      }
      if(ctx.op.getText().equals("-")){
         res= e1-e2;
         System.out.println(res);
      }
      if(ctx.op.getText().equals("*")){
         res= e1*e2;
         System.out.println(res);
      }
      if(ctx.op.getText().equals("/")){
         res= e1/e2;
         System.out.println(res);
      }

      return res;
   }
}
