
   import java.util.*;
public class Interpreter2 extends CalculatorBaseVisitor<Integer> {

   HashMap<String, Integer> variables = new HashMap<>();

   @Override public Integer visitProgram(CalculatorParser.ProgramContext ctx) {
      return visitChildren(ctx);
   }

   @Override public Integer visitStat(CalculatorParser.StatContext ctx) {
      Integer res=0;
      if(ctx.assignment()!=null){
         res = visit(ctx.assignment());
      }
      if(ctx.expression()!= null){
         System.out.println(visit(ctx.expression()));
      }
      return res;
   }

   @Override public Integer visitAssignment(CalculatorParser.AssignmentContext ctx) {
      String id = ctx.ID().getText();

      if(variables.containsKey(id)){
         System.err.println("ERROR: variable already exists");
         System.exit(-1);
      }else{
         variables.put(id, visit(ctx.expression()));
      }
      return null;
   }

   @Override public Integer visitExprAddSub(CalculatorParser.ExprAddSubContext ctx) {
      Integer i1 = visit(ctx.expression(0));
      Integer i2 = visit(ctx.expression(1));

      if(ctx.op.getText().equals("+")){
         return i1+i2;
      }else if(i2!=0){
         return i1-i2;
      }else{
         System.err.println("ERROR: cannot divide by 0");
         System.exit(-1);
      }
      return null;
   }

   @Override public Integer visitExprParent(CalculatorParser.ExprParentContext ctx) {
      return visit(ctx.expression());
   }

   @Override public Integer visitExprUnary(CalculatorParser.ExprUnaryContext ctx) {
      if(ctx.unaryOp.getText().equals("+")){
         return visit(ctx.expression());
      }else{
         return -1 * visit(ctx.expression());
      }
   }

   @Override public Integer visitExprInt(CalculatorParser.ExprIntContext ctx) {
      return Integer.parseInt(ctx.INT().getText());
   }

   @Override public Integer visitExprMultDiv(CalculatorParser.ExprMultDivContext ctx) {
      Integer i1 = visit(ctx.expression(0));
      Integer i2 = visit(ctx.expression(1));
      
      if(ctx.op.getText().equals("*")){
         return i1*i2;
      }else{
         return i1/i2;
      }
   }

   @Override public Integer visitExprID(CalculatorParser.ExprIDContext ctx) {
      String id = ctx.ID().getText();
      
      if(variables.containsKey(id)){
         System.out.println(variables.get(id));
         return variables.get(id);
      }else{
         System.out.println("ERROR: variable doesnt exists");
         System.exit(-1);
         return null;
      }
   }
}
