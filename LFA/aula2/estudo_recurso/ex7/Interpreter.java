
import java.util.*;

public class Interpreter extends CalculatorBaseVisitor<String> {

   @Override public String visitProgram(CalculatorParser.ProgramContext ctx) {
      return visitChildren(ctx);
   }

   @Override public String visitStat(CalculatorParser.StatContext ctx) {
      if(ctx.assignment()!=null){
         System.out.println(visit(ctx.assignment()));
      }
      if(ctx.expr()!= null){
         System.out.println(visit(ctx.expr()));
      }
      return null;
   }

   @Override public String visitAssignment(CalculatorParser.AssignmentContext ctx) {
      return ctx.ID().getText() + " = " + visit(ctx.expr());
   }

   @Override public String visitExprAddSub(CalculatorParser.ExprAddSubContext ctx) {
      return visit(ctx.expr(0)) + " " + visit(ctx.expr(1)) + " " + ctx.op.getText();
   }

   @Override public String visitExprParent(CalculatorParser.ExprParentContext ctx) {
      return visit(ctx.expr());
   }

   @Override public String visitExprUnary(CalculatorParser.ExprUnaryContext ctx) {
      return "!" + ctx.unaryOp.getText() + visit(ctx.expr());
   }

   @Override public String visitExprInteger(CalculatorParser.ExprIntegerContext ctx) {
      return (ctx.INTEGER().getText());
   }

   @Override public String visitExprID(CalculatorParser.ExprIDContext ctx) {
      return ctx.ID().getText();
   }

   @Override public String visitExprMultDivMod(CalculatorParser.ExprMultDivModContext ctx) {
      return visit(ctx.expr(0)) + " " + visit(ctx.expr(1)) + " " + ctx.op.getText();
   }
}
