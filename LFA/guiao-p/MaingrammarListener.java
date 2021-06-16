// Generated from Maingrammar.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MaingrammarParser}.
 */
public interface MaingrammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MaingrammarParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(MaingrammarParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link MaingrammarParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(MaingrammarParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link MaingrammarParser#stat}.
	 * @param ctx the parse tree
	 */
	void enterStat(MaingrammarParser.StatContext ctx);
	/**
	 * Exit a parse tree produced by {@link MaingrammarParser#stat}.
	 * @param ctx the parse tree
	 */
	void exitStat(MaingrammarParser.StatContext ctx);
	/**
	 * Enter a parse tree produced by {@link MaingrammarParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration(MaingrammarParser.DeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link MaingrammarParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration(MaingrammarParser.DeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StringExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterStringExpr(MaingrammarParser.StringExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StringExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitStringExpr(MaingrammarParser.StringExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code InputExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterInputExpr(MaingrammarParser.InputExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code InputExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitInputExpr(MaingrammarParser.InputExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SubExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterSubExpr(MaingrammarParser.SubExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SubExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitSubExpr(MaingrammarParser.SubExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParentExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterParentExpr(MaingrammarParser.ParentExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParentExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitParentExpr(MaingrammarParser.ParentExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SumExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterSumExpr(MaingrammarParser.SumExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SumExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitSumExpr(MaingrammarParser.SumExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link MaingrammarParser#print}.
	 * @param ctx the parse tree
	 */
	void enterPrint(MaingrammarParser.PrintContext ctx);
	/**
	 * Exit a parse tree produced by {@link MaingrammarParser#print}.
	 * @param ctx the parse tree
	 */
	void exitPrint(MaingrammarParser.PrintContext ctx);
}