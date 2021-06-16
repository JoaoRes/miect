import java.util.Iterator;
import org.antlr.v4.runtime.tree.TerminalNode;

public class Execute extends HelloBaseVisitor<String> {

   @Override public String visitChoose(HelloParser.ChooseContext ctx) {
      return visitChildren(ctx);
   }

   @Override public String visitGreetings(HelloParser.GreetingsContext ctx) {
      System.out.print("Ola "+ visit(ctx.name()) + "\n");
      return null;
   }

   @Override public String visitBye(HelloParser.ByeContext ctx) {
      System.out.print("Bye "+ visit(ctx.name()) + "\n");
      return null;
   }

   @Override public String visitName(HelloParser.NameContext ctx) {
      Iterator<TerminalNode> iter = ctx.ID().iterator();
      String res="";
      while(iter.hasNext()){
         res+= iter.next().getText() + " ";
      }
      return res.trim();
   }
}
