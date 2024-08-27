global.prec = () => {};
global.prec.left = () => {}
global.prec.right = () => {}

global.token = () => {}

let evaluations = {};
function evaluate(expression) {
  if (expression instanceof Function) {
    if (evaluations[expression.name] == undefined) {
      evaluations[expression.name] = NaN;
      let value = {
        'type': 'Function',
        'label': expression.name,
        'value': expression(global.$)
      };
      evaluations[expression.name] = value;
      return value;
    } else {
      return evaluations[expression.name];
    }
  } else if (typeof(expression) === "string") {
    return {'type': 'String'};
  } else {
    return expression;
  }
}

global.optional = (expression) => {
  return {
    'type': 'Optional',
    'value': evaluate(expression)
  };
}

global.repeat = (expression) => {
  return {
    'type': 'Repeat',
    'value': evaluate(expression)
  };
}

global.repeat1 = (expression) => {
  return {
    'type': 'Repeat1',
    'value': evaluate(expression)
  };
}

global.choice = (... expressions) => {
  return {
    'type': 'Choice',
    'value': expressions.map(expression => evaluate(expression))
  };
}

global.seq = (... expressions) => {
  return {
    'type': 'Sequence',
    'value': expressions.map(expression => evaluate(expression))
  };
}

global.field = (name, expression) => {
  return {
    'type': 'Field',
    'name': name,
    'value': evaluate(expression)
  };
}

function is_abstract_node(rule_key) {
  return rule_key.startsWith("_");
}

global.grammar = (some) => {
  global.$ = some.rules;
  Object.keys(some.rules).map(rule_key => {
    if (is_abstract_node(rule_key)) {
      let rule_fun = some.rules[rule_key];
      console.log(JSON.stringify(evaluate(rule_fun), null, 2));
    }
  });
};

require('./grammar.js');
