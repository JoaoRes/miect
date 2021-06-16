// Generated from Maingrammar.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MaingrammarParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MaingrammarVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MaingrammarParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(MaingrammarParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link MaingrammarParser#stat}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStat(MaingrammarParser.StatContext ctx);
	/**
	 * Visit a parse tree produced by {@link MaingrammarParser#declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclaration(MaingrammarParser.DeclarationContext ctx);
	/**
	 * Visit a parse tree produced by the {@code StringExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStringExpr(MaingrammarParser.StringExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code InputExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInputExpr(MaingrammarParser.InputExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SubExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubExpr(MaingrammarParser.SubExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ParentExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParentExpr(MaingrammarParser.ParentExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SumExpr}
	 * labeled alternative in {@link MaingrammarParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSumExpr(MaingrammarParser.SumExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link MaingrammarParser#print}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrint(MaingrammarParser.PrintContext ctx);
}