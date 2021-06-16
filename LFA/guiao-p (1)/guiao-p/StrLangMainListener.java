// Generated from StrLangMain.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link StrLangMainParser}.
 */
public interface StrLangMainListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link StrLangMainParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(StrLangMainParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link StrLangMainParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(StrLangMainParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link StrLangMainParser#stat}.
	 * @param ctx the parse tree
	 */
	void enterStat(StrLangMainParser.StatContext ctx);
	/**
	 * Exit a parse tree produced by {@link StrLangMainParser#stat}.
	 * @param ctx the parse tree
	 */
	void exitStat(StrLangMainParser.StatContext ctx);
	/**
	 * Enter a parse tree produced by {@link StrLangMainParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(StrLangMainParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link StrLangMainParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(StrLangMainParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprSubs}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExprSubs(StrLangMainParser.ExprSubsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprSubs}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExprSubs(StrLangMainParser.ExprSubsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprConcat}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExprConcat(StrLangMainParser.ExprConcatContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprConcat}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExprConcat(StrLangMainParser.ExprConcatContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprString}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExprString(StrLangMainParser.ExprStringContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprString}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExprString(StrLangMainParser.ExprStringContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprParent}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExprParent(StrLangMainParser.ExprParentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprParent}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExprParent(StrLangMainParser.ExprParentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprInput}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExprInput(StrLangMainParser.ExprInputContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprInput}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExprInput(StrLangMainParser.ExprInputContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprID}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExprID(StrLangMainParser.ExprIDContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprID}
	 * labeled alternative in {@link StrLangMainParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExprID(StrLangMainParser.ExprIDContext ctx);
	/**
	 * Enter a parse tree produced by {@link StrLangMainParser#print}.
	 * @param ctx the parse tree
	 */
	void enterPrint(StrLangMainParser.PrintContext ctx);
	/**
	 * Exit a parse tree produced by {@link StrLangMainParser#print}.
	 * @param ctx the parse tree
	 */
	void exitPrint(StrLangMainParser.PrintContext ctx);
}