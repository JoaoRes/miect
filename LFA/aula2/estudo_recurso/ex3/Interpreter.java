import java.util.*;
public class Interpreter extends CalculatorBaseVisitor<Double> {

   HashMap<String, Double> variables = new HashMap<>();

   @Override public Double visitProgram(CalculatorParser.ProgramContext ctx) {
      return visitChildren(ctx);
   }

   @Override public Double visitStat(CalculatorParser.StatContext ctx) {
      return visitChildren(ctx);
   }

   @Override public Double visitAssignment(CalculatorParser.AssignmentContext ctx){
      String variable = ctx.ID().getText();
      if(variables.containsKey(variable)){
         System.err.println("ERROR : variable already exists");
         System.exit(-1);
      }else{
         variables.put(variable, visit(ctx.expr()));
      }
      return null;
   }

   @Override public Double visitExprUnary(CalculatorParser.ExprUnaryContext ctx){
      if(ctx.unaryOp.getText().equals("+")){
         return (double) visit(ctx.expr());
      }else{
         return (double) visit(ctx.expr()) * -1;
      }
   }

   @Override public Double visitExprAddSub(CalculatorParser.ExprAddSubContext ctx) {
      double e1 = visit(ctx.expr(0));
      double e2 = visit(ctx.expr(1));
      double res=0;
      if(ctx.op.getText().equals("+")){
         res= e1 + e2;
      } 
      if(ctx.op.getText().equals("-")){
         res= e1-e2;
      }  
      System.out.println(res);
      return res;      
   }

   @Override public Double visitExprParent(CalculatorParser.ExprParentContext ctx) {
      return visit(ctx.expr());
   }

   @Override public Double visitExprInteger(CalculatorParser.ExprIntegerContext ctx) {
      return Double.parseDouble(ctx.INTEGER().getText());
   }

   @Override public Double visitExprID(CalculatorParser.ExprIDContext ctx){
      String variable = ctx.ID().getText();
      if(variables.containsKey(variable)){
         return variables.get(variable);
      }else{
         System.out.println("ERROR: variavel nao definida");
         System.exit(-1);
      }
      return null;
   }

   @Override public Double visitExprMultDivMod(CalculatorParser.ExprMultDivModContext ctx) {
      double e1 = visit(ctx.expr(0));
      double e2 = visit(ctx.expr(1));
      double res=0;
      if(ctx.op.getText().equals("*")){
         res= e1 * e2;
      } 
      if(ctx.op.getText().equals("/")){
         res= e1/e2;
      } 
      if(ctx.op.getText().equals("%")){
         res= e1%e2;
      } 
      System.out.println(res);
      return res;
   }
}
