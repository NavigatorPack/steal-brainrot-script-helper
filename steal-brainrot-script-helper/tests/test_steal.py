import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from scraper import scrape_script
from analyzer import analyze_script
from renderer import render_script

def test_analyze_empty_script():
    result = analyze_script("")
    assert result["lines"] == 1  # empty string split gives ['']
    assert result["functions"] == 0
    assert result["has_obfuscation"] == False

def test_analyze_simple_script():
    script = "function test()\n  print('hello')\nend"
    result = analyze_script(script)
    assert result["lines"] == 3
    assert result["functions"] == 1
    assert result["has_obfuscation"] == False

def test_analyze_obfuscated_script():
    script = "loadstring('print(1)')()"
    result = analyze_script(script)
    assert result["has_obfuscation"] == True

def test_renderer_output():
    script = "local x = function() end"
    rendered = render_script(script)
    # Should contain ANSI codes for 'function' and 'end'
    assert "\033[1;34mfunction\033[0m" in rendered
    assert "\033[1;34mend\033[0m" in rendered

if __name__ == "__main__":
    test_analyze_empty_script()
    test_analyze_simple_script()
    test_analyze_obfuscated_script()
    test_renderer_output()
    print("All tests passed.")