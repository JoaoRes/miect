// Generated from /home/oliveira/Desktop/LFA/aula2/ex1/Hello.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class HelloLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, ID=3, WS=4;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "ID", "WS"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'hello '", "'goodbye'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, "ID", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public HelloLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Hello.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\6&\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\4\6\4\34\n\4\r\4\16\4\35\3\5\6\5!\n\5\r\5\16\5\"\3\5\3"+
		"\5\2\2\6\3\3\5\4\7\5\t\6\3\2\4\4\2C\\c|\5\2\13\f\17\17\"\"\2\'\2\3\3\2"+
		"\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\3\13\3\2\2\2\5\22\3\2\2\2\7\33"+
		"\3\2\2\2\t \3\2\2\2\13\f\7j\2\2\f\r\7g\2\2\r\16\7n\2\2\16\17\7n\2\2\17"+
		"\20\7q\2\2\20\21\7\"\2\2\21\4\3\2\2\2\22\23\7i\2\2\23\24\7q\2\2\24\25"+
		"\7q\2\2\25\26\7f\2\2\26\27\7d\2\2\27\30\7{\2\2\30\31\7g\2\2\31\6\3\2\2"+
		"\2\32\34\t\2\2\2\33\32\3\2\2\2\34\35\3\2\2\2\35\33\3\2\2\2\35\36\3\2\2"+
		"\2\36\b\3\2\2\2\37!\t\3\2\2 \37\3\2\2\2!\"\3\2\2\2\" \3\2\2\2\"#\3\2\2"+
		"\2#$\3\2\2\2$%\b\5\2\2%\n\3\2\2\2\5\2\35\"\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}