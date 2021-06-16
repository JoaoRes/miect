// Generated from StrLangMain.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link StrLangMainParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface StrLangMainVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link StrLangMainParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(StrLangMainParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link StrLangMainParser#stat}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStat(StrLangMainParser.StatContext ctx);
	/**
	 * Visit a parse tree produced by {@link StrLangMainParser#assignment}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignment(StrLangMainParser.AssignmentContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ExprSubs}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprSubs(StrLangMainParser.ExprSubsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ExprConcat}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprConcat(StrLangMainParser.ExprConcatContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ExprString}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprString(StrLangMainParser.ExprStringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ExprParent}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprParent(StrLangMainParser.ExprParentContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ExprInput}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprInput(StrLangMainParser.ExprInputContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ExprID}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprID(StrLangMainParser.ExprIDContext ctx);
	/**
	 * Visit a parse tree produced by {@link StrLangMainParser#print}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrint(StrLangMainParser.PrintContext ctx);
}