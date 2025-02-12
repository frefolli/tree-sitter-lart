import XCTest
import SwiftTreeSitter
import TreeSitterLart

final class TreeSitterLartTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_lart())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Lart grammar")
    }
}
