import UIKit

@IBDesignable
class RoundButton: UIButton {

    enum ButtonState {
        case normal
        case disabled
    }
    
    private var disabledBackgroundColor: UIColor?
    private var defaultBackgroundColor: UIColor? {
        didSet {
            backgroundColor = defaultBackgroundColor
        }
    }
    
    override var isEnabled: Bool {
        didSet {
            if isEnabled {
                if let color = defaultBackgroundColor {
                    //self.backgroundColor = color
                    self.tintColor = color
                }
            }
            else {
                if let color = disabledBackgroundColor {
                    //self.backgroundColor = color
                    self.tintColor = color
                }
            }
        }
    }
    
    func setBackgroundColor(_ color: UIColor?, for state: ButtonState) {
        switch state {
        case .disabled:
            disabledBackgroundColor = color
        case .normal:
            defaultBackgroundColor = color
        }
    }
    
    @IBInspectable var cornerRadius: CGFloat = 0{
        didSet{
        self.layer.cornerRadius = cornerRadius
        self.clipsToBounds = true
        self.configuration?.cornerStyle = .capsule
        self.titleLabel?.textColor = .black
        self.tintColor = .white
        }
    }

    @IBInspectable var borderWidth: CGFloat = 0{
        didSet{
            self.layer.borderWidth = borderWidth
        }
    }

    @IBInspectable var borderColor: UIColor = UIColor.clear{
        didSet{
            self.layer.borderColor = borderColor.cgColor
        }
    }
    
    
}
