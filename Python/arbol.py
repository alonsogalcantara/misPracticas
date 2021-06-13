class expr:
    pass

class times(expr):
    def __init__(self, l, r):
        self.l=l
        self.r=r
        pass

    def __str__(self):
        return '('+str(self.l)+'*'+str(self.r)+')'

    def eval(self, env):
        return self.l.eval(env) * self.r.eval(env)
    pass


class plus(expr):
    def __init__(self, l, r):
        self.l = l
        self.r = r
        pass

    def __str__(self):
        return '('+str(self.l)+'+'+str(self.r)+')'

    def eval(self, env):
        return self.l.eval(env) + self.r.eval(env)
    pass

class const(expr):
    def __init__(self, val):
        self.val = val
        pass

    def __str__(self):
        return str(self.val)

    def eval(self, env):
        return self.val
    pass


class var(expr):
    def __init__(self, name):
        self.name = name
        pass

    def __str__(self):
        return self.name

    def eval(self, env):
        return env[self.name]
    pass

if __name__ == '__main__':
    e1 = times(const(3), plus(var('y'), var('x')))
    e2 = plus(times(const(3), var('y')), var('x'))
    env = {'x': 10, 'y': 5}
    print(e1)
    print(e1.eval(env))
    print(e2)
    print(e2.eval(env))
    pass
