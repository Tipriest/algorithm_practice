public interface UserService {
    void sayHello();
}

public class UserServiceImpl implements UserService {
    @Override
    public void sayHello() {
        System.out.println("Hello, world!");
    }
}

public class UserController {
    private UserService userService;

    public void setUserService(UserService userService) {
        this.userService = userService;
    }

    public void sayHello() {
        userService.sayHello();
    }
}

public class Main {
    public static void main(String[] args) {
        // 创建一个 UserController 对象
        UserController controller = new UserController();
         // 创建一个 UserServiceImpl 对象并注入到 UserController 中
        UserService userService = new UserServiceImpl();
        controller.setUserService(userService);
         // 调用 UserController 的 sayHello 方法
        controller.sayHello();
    }
}