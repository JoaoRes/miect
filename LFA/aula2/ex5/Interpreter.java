import java.util.HashMap;

public class Interpreter extends CalculatorBaseVisitor<Integer> {

   HashMap<String,Integer> variaveis = new HashMap<>() ;

   @Override public Integer visitProgram(CalculatorParser.ProgramContext ctx) {
      return visitChildren(ctx);
   }

   @Override public Integer visitExpression(CalculatorParser.ExpressionContext ctx) {
      if(ctx.expr() != null){
         System.out.println("Resultado = " + visit(ctx.expr()));
      }
      return 0;
   }

   @Override public Integer visitVariable(CalculatorParser.VariableContext ctx) {
      if(ctx.assignment() != null){
         visit(ctx.assignment());
         System.out.println("👍");
         return 0;
      }
      return -1;
   }

   @Override public Integer visitAssignment(CalculatorParser.AssignmentContext ctx) {
      int n = visit(ctx.expr());
      variaveis.put(ctx.ID().getText(),n);
      return 0;
   }

   @Override public Integer visitExprAddSub(CalculatorParser.ExprAddSubContext ctx) {
      int v1 = visit(ctx.expr(0));
      int v2 = visit(ctx.expr(1));
   
      switch(ctx.op.getText())
      {
         case "+":
            return v1+v2;
         
         case "-": 
            return v1-v2;
      }
      
      return 0;
   }

   @Override public Integer visitExprIntegerSignal(CalculatorParser.ExprIntegerSignalContext ctx) {
      switch(ctx.op.getText())
      {
         case "-":
         return -visit(ctx.expr());
         
         case "+":
         return visit(ctx.expr());
      }
      return 0;
   }


   @Override public Integer visitExprParent(CalculatorParser.ExprParentContext ctx) {
      return visit(ctx.expr());
   }

   @Override public Integer visitExprInteger(CalculatorParser.ExprIntegerContext ctx) {
      return Integer.parseInt(ctx.Integer().getText());
   }

   @Override public Integer visitExprID(CalculatorParser.ExprIDContext ctx) {
      return variaveis.get(ctx.ID().getText());
   }

   @Override public Integer visitExprMultDivMod(CalculatorParser.ExprMultDivModContext ctx) {
      int v1 = visit(ctx.expr(0));
      int v2 = visit(ctx.expr(1));
   
      switch(ctx.op.getText())
      {
         case "*":
            return Math.round(v1*v2);
         
         case "/": 
            return Math.round(v1/v2);
         
         case "%": 
         return Math.round(v1%v2);
      }
      return 0;
   }
}
