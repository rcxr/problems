// Main function, the entry point for the engine
$(function() {
  var INPUT_MODE = 1; var OUTPUT_MODE = 2;
  var inputMode = INPUT_MODE;

  var content = $("#content");

  var write = function(text, mode) {
    if (mode == inputMode) {
      content.append(text + "<br />");
    }
  };
  var input = function(text) { write(text, INPUT_MODE); };
  var output = function(text) { write(text, OUTPUT_MODE); };

  // test case 08
  // input(1200);
  // var results = [];
  // for (var i = 0; i < 1200; i++) {
  //   input("_" + i + " _" + (i + 1));
  //   if (0 < i) { results.push("_" + (i + 1)); }
  // }
  // results.sort();
  // output(results.join(" "));

  // test cases involving large trees
  var results = [];
  var addRelationships = function(n, m, parent) {
    if (m === 1) { return; }

    if (3 <= m) {
      results.push(parent);
    }

    for (var i = 0; i < n; i++) {
      var child = parent + "_" + i;
      input(child + " " + parent);
      addRelationships(n, m - 1, child);
    }
  };

  var n = 34;
  var m = 3;
  var familySize = (Math.pow(n, m) - 1) / (n - 1) - 1;

  input(familySize);
  addRelationships(n, m, "root");

  results.sort();
  output(results.join(" "));
});
